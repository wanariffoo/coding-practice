#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include "../library/mycuda.h"
#include <chrono>


using namespace std;

// a = b + c
__global__
void add(int *a, int *b, int *c, size_t N)
{

    int id = blockDim.x * blockIdx.x + threadIdx.x;

    if ( id < N )
        a[id] = b[id] + c[id];
    
}

int main()
{

    size_t N = 800000;

    // host variables

    vector<int> a(N, 0);
    vector<int> b(N, 1);
    vector<int> c(N, 2);
    vector<int> d(N, 3);

    // block and grid dimensions
    dim3 blockDim;
    dim3 gridDim;

    calculateDimensions(N, blockDim, gridDim);

    // device pointers

    int* d_a;
    int* d_b;
    int* d_c;

    // allocate and copy to device

    CUDA_CALL( cudaMalloc((void**)&d_a, sizeof(int) * N) );
    CUDA_CALL( cudaMalloc((void**)&d_b, sizeof(int) * N) );
    CUDA_CALL( cudaMalloc((void**)&d_c, sizeof(int) * N) );

    CUDA_CALL( cudaMemcpy(d_a, &a[0], sizeof(int) * N, cudaMemcpyHostToDevice) );
    CUDA_CALL( cudaMemcpy(d_b, &b[0], sizeof(int) * N, cudaMemcpyHostToDevice) );
    CUDA_CALL( cudaMemcpy(d_c, &c[0], sizeof(int) * N, cudaMemcpyHostToDevice) );
    
    


    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    
    
    
    // run kernel
    
    add<<<gridDim, blockDim>>>(d_a, d_b, d_c, N);
    cudaDeviceSynchronize();
 
    
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<std::endl;
    
    
    
    CUDA_CALL( cudaMemcpy(&a[0], d_a, sizeof(int) * N, cudaMemcpyDeviceToHost) );
    

    // verify d_c

    int checker = 0;

    for(int i = 0 ; i < d.size() ; ++i)
    {
        if ( a[i] != d[i] )
            checker++;
    }


    if ( checker > 0 )
        cout << "GPU: fail" << endl;
    
    else
        cout << "GPU: pass" << endl;

    // deallocate memory in device

    CUDA_CALL( cudaFree(d_a) );
    CUDA_CALL( cudaFree(d_b) );
    CUDA_CALL( cudaFree(d_c) );


    // compare with CPU

    vector<int> h_a(N, 0);
    vector<int> h_b(N, 1);
    vector<int> h_c(N, 2);


    begin = std::chrono::steady_clock::now();
    
    for(int i = 0 ; i < d.size() ; ++i)
    {
        h_a[i] = h_b[i] + h_c[i];
    }
    
    end= std::chrono::steady_clock::now();
    
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<std::endl;
 
    int h_checker = 0;

    for(int i = 0 ; i < d.size() ; ++i)
    {
        if ( a[i] != d[i] )
            h_checker++;
    }

    if ( h_checker > 0 )
        cout << "CPU: fail" << endl;
    
    else
        cout << "CPU: pass" << endl;



}