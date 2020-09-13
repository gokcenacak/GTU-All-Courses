import random
import numpy as np


def q1_box_problem(boxlist,shouldswap):
    if shouldswap:
        swap(boxlist,0,len(boxlist)-1)
        shouldswap = False
    else:
        shouldswap = True

    if len(boxlist) > 2:
        q1_box_problem(boxlist[1:len(boxlist)-1],shouldswap)
    return boxlist


def swap(originallist, index1, index2):
    temp = originallist[index1]
    originallist[index1] = originallist[index2]
    originallist[index2] = temp


def q2_fake_coin_problem(coinlist):
    if len(coinlist) == 1:
        return coinlist
    elif len(coinlist) == 2:
        if min(coinlist[0], coinlist[1]) == coinlist[0]:
            return q2_fake_coin_problem(coinlist[0:1])
        else:
            return q2_fake_coin_problem(coinlist[1:2])
    else:
        n = int(len(coinlist)/3)
        pile1 = coinlist[0:n]
        pile2 = coinlist[n:2*n]
        pile3 = coinlist[2*n:]
        if calculate_total_weight(pile1) == calculate_total_weight(pile2):
            return q2_fake_coin_problem(pile3)
        else:
            if calculate_min_weighted_pile(pile1,pile2) == pile1:
                return q2_fake_coin_problem(pile1)
            else:
                return q2_fake_coin_problem(pile2)


def calculate_total_weight(coinlist):
    total = 0
    for coinweight in coinlist:
        total += coinweight
    return total


def calculate_min_weighted_pile(pile1, pile2):
    if calculate_total_weight(pile1) < calculate_total_weight(pile2):
        return pile1
    else:
        return pile2



def quicksort(array, leftindex, rightindex, swapcount):
    if leftindex < rightindex :
        #pivotindex = random.randrange(leftindex, rightindex + 1)
        pivotindex, swapcounttoadd = arrange(array, leftindex, rightindex, rightindex, swapcount)
        swapcount += swapcounttoadd
        swapcount += quicksort(array, leftindex, pivotindex-1, 0)
        swapcount += quicksort(array, pivotindex+1, rightindex, 0)
    return swapcount

def insertion_sort(array):
    swapcount = 0
    for i in range(1,len(array)):
        key = array[i]
        j=i-1
        while j>=0 and key < array[j]:
            array[j+1] = array[j]
            swapcount += 1
            j -= 1
        array[j+1] = key

    return swapcount


def arrange(array, leftindex, rightindex, pivotindex, swapcount):
    valueatpivot = array[pivotindex]
    swap(array, pivotindex, rightindex)
    lastpivotindex = leftindex
    for i in range(leftindex, rightindex):
        if array[i] < valueatpivot:
            swap(array, lastpivotindex, i)
            swapcount += 1
            lastpivotindex += 1
    swap(array, rightindex, lastpivotindex)
    swapcount += 1
    return lastpivotindex,swapcount


def q4_median_of_unsorted_array(array, leftindex, rightindex):
    if leftindex == rightindex:
        return array[leftindex]
    pivotindex = random.randrange(leftindex, rightindex+1)
    pivotindex, _ = arrange(array, leftindex, rightindex, pivotindex, 0)
    arraylen = len(array)
    midpoint = int(arraylen/2)
    if midpoint == pivotindex:
        return array[midpoint]
    elif midpoint < pivotindex:
        return q4_median_of_unsorted_array(array, leftindex, pivotindex-1)
    else:
        return q4_median_of_unsorted_array(array, pivotindex+1, rightindex)


def q5_optimal_subarray(A):
    condsum = (min(A) + max(A)) * float(len(A)/4)
    condsatisfyingsubsets = subsets(A,condsum)
    multiplicationsarray = []
    for i in range(0,int(len(condsatisfyingsubsets))):
        multiplication = 1
        for j in condsatisfyingsubsets[i]:
            multiplication *= j
        multiplicationsarray.append(multiplication)
    return condsatisfyingsubsets[multiplicationsarray.index(min(multiplicationsarray))]


def subsets(A, condsum):
    sets = [A]
    for i in range(0, len(A)):
        temp_subsets = subsets(A[:i] + A[i+1:],condsum)
        for subset in temp_subsets:
            if subset not in sets and calculate_total_weight(subset) >= condsum:
                sets.append(subset)
    return sets

def q1_test():
    boxlist = np.array(['B','B','B','B','W','W','W','W'])
    boxlist1 = np.array(['B','B','W','W'])
    boxlist2 = np.array(['B','B','B','W','W','W'])

    print("-- Test for Part 1 --")
    print("CASE 1:")
    print(f"Input: {boxlist}")
    print(f"Result: {q1_box_problem(boxlist, False)}")
    print("CASE 2:")
    print(f"Input: {boxlist1}")
    print(f"Result: {q1_box_problem(boxlist1, False)}")
    print("CASE 3:")
    print(f"Input: {boxlist2}")
    print(f"Result: {q1_box_problem(boxlist2, False)}")

def q2_test():
    coinlist = [2,2,2,2,2,1]
    coinlist1 = [2,2,2,1,2,2,2]
    coinlist2 = [1,2,2,2]

    print("-- Test for Part 2 --")
    print("CASE 1:")
    print(f"Input: {coinlist}")
    print(f"Fake Coin: {q2_fake_coin_problem(coinlist)} ")
    print("CASE 2:")
    print(f"Input: {coinlist1}")
    print(f"Fake Coin: {q2_fake_coin_problem(coinlist1)} ")
    print("CASE 3:")
    print(f"Input: {coinlist2}")
    print(f"Fake Coin: {q2_fake_coin_problem(coinlist2)} ")

def q3_test():
    numlistinsers = [1, 3, 9, 8, 2, 7, 5]
    numlistquicks = [1, 3, 9, 8, 2, 7, 5]
    numlist = [2, 4, 8, 1, 5, 6]
    numlist1 = [6, 3, 5, 4, 1, 9, 7]

    print("-- Test for Part 3 --")
    print(f"Testing quicksort for array {numlist}...")
    quicksort(numlist, 0, int(len(numlist) - 1), 0)
    print(f"Result: {numlist}")
    print(f"Testing insertion sort for array {numlist1}...")
    insertion_sort(numlist1)
    print(f"Result: {numlist1}")
    print(f"Comparing swap counts for both insertion sort and quicksort for array {numlistinsers}")
    print(f"Insertion sort swap count is: {insertion_sort(numlistinsers)}")
    print(f"Quick sort swap count is: {quicksort(numlistquicks, 0, int(len(numlistquicks) - 1), 0)}")

def q4_test():
    numlist = [1,9,5,7,3,4,0]
    numlist1 = [6,4,3,75,1,2,46,11,12]
    numlist2 = [6,2,14,34,1,5,3,0,46]
    print("-- Test for Part 4 --")
    print("CASE 1:")
    print(f"Input: {numlist}")
    print(f"Median: {q4_median_of_unsorted_array(numlist, 0, int(len(numlist) - 1))}")
    print("CASE 2:")
    print(f"Input: {numlist1}")
    print(f"Median: {q4_median_of_unsorted_array(numlist1, 0, int(len(numlist1) - 1))}")
    print("CASE 3:")
    print(f"Input: {numlist2}")
    print(f"Median: {q4_median_of_unsorted_array(numlist2, 0, int(len(numlist2) - 1))}")

def q5_test():
    numlist = [2, 4, 7, 5, 22, 11]
    numlist1 = [6,9,10,2,4]
    numlist2 = [9,3,7,12,1,6]
    print("CASE 1:")
    print(f"Input: {numlist}")
    print(f"Optimal Subarray: {q5_optimal_subarray(numlist)}")
    print("CASE 2:")
    print(f"Input: {numlist1}")
    print(f"Optimal Subarray: {q5_optimal_subarray(numlist1)}")
    print("CASE 3:")
    print(f"Input: {numlist2}")
    print(f"Optimal Subarray: {q5_optimal_subarray(numlist2)}")

def main():
    q1_test()
    q2_test()
    q3_test()
    q4_test()
    q5_test()

if __name__ == '__main__':
    main()
