#include <cuda.h>
#include <cuda_runtime.h>

#define CUDA_CALL( call )                                                                                          \
{                                                                                                                  \
cudaError_t err = call;                                                                                          \
if ( cudaSuccess != err)                                                                                         \
    fprintf(stderr, "CUDA error for %s in line %d of %s : %s.\n", #call , __LINE__ , __FILE__ ,cudaGetErrorString(err));\
}


__device__ double atomicAdd_double(double* address, double val)
{
    unsigned long long int* address_as_ull =
                                (unsigned long long int*)address;
    unsigned long long int old = *address_as_ull, assumed;

    do {
        assumed = old;
        old = atomicCAS(address_as_ull, assumed,
                        __double_as_longlong(val +
                                __longlong_as_double(assumed)));

    } while (assumed != old);

    return __longlong_as_double(old);
}

// Determines 1-dimensional CUDA block and grid sizes based on the number of rows N
__host__ 
void calculateDimensions(size_t N, dim3 &blockDim, dim3 &gridDim)
{
    if ( N <= 1024 )
    {
        blockDim.x = N;
        gridDim.x  = 1;
    }
        
    else
    {
        blockDim.x = 1024;
        gridDim.x  = (int)ceil(N/blockDim.x)+1;
    }
}

__global__ void print_GPU(double* x){

        printf("[GPU] x = %e\n", *x);
}

__global__ void print_GPU(int* x){

        printf("[GPU] x = %d\n", *x);
}

__global__ void print_GPU(size_t* x){

        printf("[GPU] x = %lu\n", *x);
}

__global__ void print_GPU(bool* x){

        printf("[GPU] x = %d\n", *x);
}


__global__ void printVector_GPU(double* x, size_t N){

    int id = blockDim.x * blockIdx.x + threadIdx.x;

    if( id < N)
        printf("[GPU] x[%d] = %e\n", id, x[id]);
}

__global__ void printVector_GPU(std::size_t* x, size_t N){

    int id = blockDim.x * blockIdx.x + threadIdx.x;

    if( id < N)
        printf("[GPU] x[%d] = %lu\n", id, x[id]);
}

__global__ void printVector_GPU(int* x, size_t N){

    int id = blockDim.x * blockIdx.x + threadIdx.x;

    if( id < N)
        printf("[GPU] x[%d] = %d\n", id, x[id]);
}

// x = a[] * b[]
__global__ void dotProduct(double* x, double* a, double* b){

    int id = blockDim.x * blockIdx.x + threadIdx.x;
    *x = 0;
    atomicAdd_double( x, a[id]*b[id] );
}

// (scalar) a = b
__global__ void equals_GPU(double* a, double* b){

    *a = *b;
}

// a[] = b[]
__global__ void vectorEquals_GPU(double* a, double* b){

    int id = blockDim.x * blockIdx.x + threadIdx.x;

    a[id] = b[id];

}


// a[] = 0
__global__ void setToZero(double* a){

    int id = blockDim.x * blockIdx.x + threadIdx.x;

    a[id] = 0.0;
}


//TODO: Name change, it's not just corrections, see cg.cu:264
// x += c
__global__ void addCorrection_GPU(double* x, double* c){

	int id = blockDim.x * blockIdx.x + threadIdx.x;

	atomicAdd_double( &x[id], c[id] );
}


// x += c
__global__ void addVector_GPU(double *x, double *c){

	int id = blockDim.x * blockIdx.x + threadIdx.x;

	x[id] += c[id];
}

// x = x + alpha * p
__global__ void axpy_GPU(double* d_x, double* d_alpha, double* d_p){

	int id = blockDim.x * blockIdx.x + threadIdx.x;

	d_x[id] += (*d_alpha * d_p[id]);
}

// x = x - alpha * p
__global__ void axpy_neg_GPU(double* d_x, double* d_alpha, double* d_p){

	int id = blockDim.x * blockIdx.x + threadIdx.x;

	// printf("id = %d : %e - %e * %e = %e\n", id, d_x[id], *d_alpha, d_p[id], d_x[id] - (*d_alpha * d_p[id]));
	// printf("temp[%d]= %e\n", id, temp);
	// d_x[id] = d_x[id] - ( (*d_alpha) * d_p[id] );
	// d_x[id] = d_x[id] - (*d_alpha * d_p[id]);	//TODO: something weird going on here

	// if ( id == 0 )
	// printf("id = %d : d_x(before) = %e, d_alpha = %e, d_p = %e\n", id, d_x[id], *d_alpha, d_p[id]);

	d_x[id] = d_x[id] - ( (*d_alpha) * (d_p[id]) );
	
	// if ( id == 1 )
	// printf("id = %d : d_x(after) = %e\n", id, d_x[id] );
}


// norm = x.norm()
__global__ void norm_GPU(double* norm, double* x){

	int id = blockDim.x * blockIdx.x + threadIdx.x;

	*norm = 0;

	atomicAdd_double( norm, x[id]*x[id] );
	
	__syncthreads();

	*norm = sqrt(*norm);


}
