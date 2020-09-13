def kthelement(arr1, start1, end1, arr2, start2, end2, k):
    if start1 >= end1:
        return arr2[k]
    if start2 >= end2:
        return arr1[k]

    mida1 = (end1-start1) // 2
    mida2 = (end2-start2) // 2

    if mida1 + mida2 < k:
        if arr1[mida1] > arr2[mida2]:
            return kthelement(arr1, start1, end1, arr2, mida2+1, end2, k - mida2 - 1)
        else:
            return kthelement(arr1, mida1+1, end1, arr2, start2, end2, k - mida1 - 1)
    else:
        if arr1[mida1] > arr2[mida2]:
            return kthelement(arr1, start1, mida1, arr2, start2, end2, k)
        else:
            return kthelement(arr1, start1, end1, arr2, start2, mida2, k)


def bipartite_check(adjlist, setlist, visitedlist, node):
    for connectedNode in adjlist[node]:
        if not visitedlist[connectedNode]:
            visitedlist[connectedNode] = True
            setlist[connectedNode] = not setlist[node]
            if not bipartite_check(adjlist, setlist, visitedlist, connectedNode):
                return False
        elif setlist[connectedNode] == setlist[node]:
            return False

    return True


def max_subarray_sum_including_middle(arr,leftindex,middleindex,rightindex):
    sum = 0
    leftsum = -2147483648
    subarray_leftindex =leftindex
    subarray_rightindex = rightindex
    for i in range(middleindex, leftindex - 1, -1):
        sum = sum + arr[i]
        if sum > leftsum:
            leftsum = sum
            subarray_leftindex = i

    sum = 0
    rightsum = -2147483648

    for i in range(middleindex + 1, rightindex + 1):
        sum = sum + arr[i]
        if (sum > rightsum):
            rightsum = sum
            subarray_rightindex = i

    return leftsum + rightsum, subarray_leftindex ,subarray_rightindex


def max_subarray_sum(arr,leftindex,rightindex):
    if leftindex == rightindex:
        return arr[leftindex], leftindex, rightindex

    middle = (leftindex + rightindex) // 2
    leftmax ,lli, lri = max_subarray_sum(arr,leftindex, middle)
    rightmax, rli, rri = max_subarray_sum(arr,middle+1, rightindex)
    crossingmax ,crossingmax_li , crossingmax_ri = max_subarray_sum_including_middle(arr,leftindex,middle,rightindex)

    if max(leftmax,rightmax,crossingmax) == leftmax:
        return leftmax,lli,lri
    elif max(leftmax,rightmax,crossingmax) == rightmax:
        return rightmax,rli,rri
    else:
        return crossingmax,crossingmax_li,crossingmax_ri


def finding_subarray_with_max_sum(arr):
    sum, leftindex, rightindex = max_subarray_sum(arr,0,len(arr)-1)
    print(f'Maximum sum of a contiguous subarray is {sum} with the subarray {arr[leftindex:rightindex+1]}')
    return arr[leftindex:rightindex+1]


def calculate_gain(costs,prices):
    gain = [0] * len(costs)
    for i in range(1,len(costs)):
        if prices[i] != '-' or costs[i-1] != '-':
            gain[i-1] = prices[i] - costs[i-1]
    max_gain, day = calculate_max(gain,0,len(gain)-1)
    if max_gain <= 0:
        print('There is no good day to sell goods, all sales cause no gain')
    else:
        print(f'Best day to buy goods is day {day + 1} because you can get the maximum gain of {max_gain}')


def calculate_max(gain,start,end):
    if start == end:
        return gain[start],start
    if end == start + 1 :
        if gain[start] > gain[end]:
            return gain[start], start
        else:
            return gain[end], end

    mid = (start + end) // 2
    left_max, left_max_day = calculate_max(gain,start,mid)
    right_max, right_max_day = calculate_max(gain,mid,end)

    if left_max > right_max:
        return left_max, left_max_day
    else:
        return right_max, right_max_day


def leftmost_minimum_element(arr,minimumlist):
    if len(arr) == 1:
        mintuple = min(arr[0][0]),arr[0][1], arr[0][0].index(min(arr[0][0]))
        minimumlist.append(mintuple)
        return
    evenrows = []
    oddrows = []

    for i in range(0, len(arr)):
        if i % 2 == 0:
            evenrows.append(arr[i])
        else:
            oddrows.append(arr[i])

    leftmost_minimum_element(evenrows,minimumlist)
    leftmost_minimum_element(oddrows,minimumlist)

    return minimumlist


def add_row_numbers_to_array(arr):
    for i in range(0,len(arr)):
        rowtuple = arr[i],i
        arr[i] = rowtuple


def question_1_test():
    print("TEST FOR QUESTION #1")
    list = [[5, 2, 3, 4],
            [0, 5, 4, 5],
            [1, 2, 2, 8],
            [10, 15, 7, 7],
            [14,17,18,19],
            [24,14,16,14]]

    print(f"TEST 1 : For array {list} leftmost minimums are :")
    add_row_numbers_to_array(list)
    print("PS: First element represents the value, second element represents the row number and third element represents the column number")
    print("PS: They are not ordered, meaning except for list[0], list[n] does not mean the leftmost minimum of the row n.")
    minlist = []
    print(leftmost_minimum_element(list,minlist))


def question_2_test():
    print("TEST FOR QUESTION #2")
    first_list = [8,9,16,17,20]
    second_list = [2, 5, 16, 17, 24]
    k = 5
    print(f'TEST 1 : A = {first_list} B = {second_list} K = {k} : {kthelement(first_list,0,len(first_list),second_list,0,len(second_list),k-1)}')


def question_3_test():
    print("TEST FOR QUESTION #3")
    list = [-5,6,12,4,-8,-9]
    print(f'TEST 1 with A = {list} ')
    finding_subarray_with_max_sum(list)


def question_4_test():
    print("TEST FOR QUESTION #4")
    adjList = [[1,2],
               [0,3],
               [0,4],
               [1,4],
               [2,3]]

    adjList1 = [[1],
                [2,5],
                [1,3],
                [2],
                [5],
                [4,6],
                [5,7],
                [6]]

    setlist = [0] * len(adjList)
    visitedlist = [False for i in range(len(adjList))]
    visitedlist[0] = True
    setlist[0] = True
    setlist1 = [0] * len(adjList1)
    visitedlist1 = [False for i in range(len(adjList1))]
    visitedlist1[0] = True
    setlist1[0] = True

    print(f'TEST 1 : Is graph with adjacency list {adjList} bipartite? : {bipartite_check(adjList,setlist,visitedlist,0)}')
    print(f'TEST 2 : Is graph with adjacency list {adjList1} bipartite? : {bipartite_check(adjList1,setlist1,visitedlist1,0)}')


def question_5_test():
    print("TEST FOR QUESTION #5")
    costs = [5, 11, 2, 21, 5, 7, 8, 12, 13, '-']
    prices = ['−', 4, 10, 1, 20, 4, 6, 7, 11, 12]

    costs1 = [5, 11, 2, 21, 5, 7, 8, 12, 13, '−']
    prices1 = ['−', 7, 9, 5, 21, 7, 13, 10, 14, 20]
    print(f"TEST 1 : Costs = {costs}  Prices={prices}")
    calculate_gain(costs,prices)
    print(f"TEST 2 : Costs = {costs1}  Prices={prices1}")
    calculate_gain(costs1,prices1)


def main():
    question_1_test()
    question_2_test()
    question_3_test()
    question_4_test()
    question_5_test()


main()

