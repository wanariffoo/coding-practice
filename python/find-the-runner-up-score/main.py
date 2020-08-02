# https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem

if __name__ == '__main__':
    # n = int(input())
    # arr = map(int, input().split())

    n = 5
    arr = [2,3,6,6,5]

    # store in a set
    set_arr = set(arr)

    # sort set
    sorted_set = sorted( set_arr )

    # get second from last
    print( sorted_set[-2] )

    # can be shortened to :
    # print( sorted( set(arr) )[-2])


