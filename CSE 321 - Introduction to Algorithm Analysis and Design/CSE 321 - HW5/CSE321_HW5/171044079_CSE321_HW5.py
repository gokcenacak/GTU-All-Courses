def part_1(ny_cost_list, sf_cost_list, moving_cost):
    ny_optimal_solution = []
    sf_optimal_solution = []
    ny_optimal_solution.append(0)
    sf_optimal_solution.append(0)

    for i in range(1,len(ny_cost_list) + 1):
        if min(ny_optimal_solution[i-1],sf_optimal_solution[i-1] + moving_cost) == ny_optimal_solution[i-1]:
            ny_optimal_solution.append(ny_cost_list[i - 1] + ny_optimal_solution[i - 1])
        else:
            ny_optimal_solution.append(ny_cost_list[i-1] + sf_optimal_solution[i-1] + moving_cost)
        if min(sf_optimal_solution[i-1],ny_optimal_solution[i-1] + moving_cost) == sf_optimal_solution[i-1]:
            sf_optimal_solution.append(sf_cost_list[i-1] + sf_optimal_solution[i-1])
        else:
            sf_optimal_solution.append(sf_cost_list[i-1] + ny_optimal_solution[i-1] + moving_cost)

    return min(ny_optimal_solution[len(ny_optimal_solution)-1],sf_optimal_solution[len(sf_optimal_solution)-1])


def part_2(session_list):
    finish_time = 0
    max_session_list = []
    sorted_session_list = sorted(session_list, key=lambda x: x[2])
    for i in range(0,len(sorted_session_list)):
        if finish_time <= sorted_session_list[i][1]:
            max_session_list.append(sorted_session_list[i])
            finish_time = sorted_session_list[i][2]

    return max_session_list


def print_sessions(session_list):
    print("Sessions held in the symposium are:")
    for i in range(0,len(session_list)):
        print(f'{session_list[i][0]} Start:{session_list[i][1]} End:{session_list[i][2]}')


def part_3(list,sum):
    dp_table = [[0 for i in range(sum+1)] for j in range(len(list)+1)]

    for i in range(0,len(list)+1):
        dp_table[i][0] = True

    for i in range(1,sum+1):
        dp_table[0][i] = False

    for i in range(1,len(list) + 1):
        for j in range(1,sum+1):
            if j < list[i-1]:
                dp_table[i][j] = dp_table[i-1][j]
            if j >= list[i-1]:
                dp_table[i][j] = dp_table[i-1][j] or dp_table[i - 1][j - list[i-1]]

    return dp_table[len(list)][sum]


def part_4(s1,s2,match_score, mismatch_score, gap_score):
    col_count = len(s1) + 1
    row_count = len(s2) + 1

    dp_table = initialize_dp_table(gap_score,row_count,col_count)

    for i in range(1,len(dp_table)):
        for j in range(1,len(dp_table[0])):
            above_cell = dp_table[i][j-1]
            left_cell = dp_table[i-1][j]
            left_above_cell = dp_table[i-1][j-1]
            left_score = left_cell + gap_score
            above_score = above_cell + gap_score
            if s1[j-1] == s2[i-1]:
                left_above_score = left_above_cell + match_score
            else:
                left_above_score = left_above_cell + mismatch_score

            if max(left_above_score,left_score,above_score) == left_above_score:
                dp_table[i][j] = left_above_score

            elif max(left_above_score,left_score,above_score) == left_score:
                dp_table[i][j] = left_score
            else:
                dp_table[i][j] = above_score

    return dp_table[len(s2)][len(s1)]


def initialize_dp_table(gap_score, row_count, col_count):
    dp_table = [[0 for i in range(col_count)] for j in range(row_count)]
    for i in range(1,len(dp_table[0])):
        dp_table[0][i] = i * gap_score
    for i in range(1,len(dp_table)):
        dp_table[i][0] = i * gap_score

    return dp_table


def part_5(list):
    list.sort()
    operations = 0
    while len(list) > 1:
        min_in_list = min(list)
        list.remove(min_in_list)
        second_min_in_list = min(list)
        list.remove(second_min_in_list)
        sum =min_in_list+second_min_in_list
        operations += sum
        list.append(sum)

    return operations


def part_1_test():
    print("---TEST FOR PART 1---")
    ny = [2,4,10,20,2,4,8]
    sf = [10,2,3,5,6,8,9]
    print(f'The minimum cost of the optimal moving plan is : {part_1(ny,sf,5)}')


def part_2_test():
    print("---TEST FOR PART 2---")
    session_list = [["S1", 0, 6],["S2", 1, 2],["S3", 3, 4], ["S4", 5, 7], ["S5", 5, 9], ["S6", 8, 9]]
    print_sessions(session_list)
    result = part_2(session_list)
    print(f'Maximum number of sessions is {len(result)} with the schedule {result}')


def part_3_test():
    print("---TEST FOR PART 3---")
    print("NOT IMPLEMENTED")
    #list = [1,2,3]
    #print(part_3(list,0))
    return


def part_4_test():
    print("---TEST FOR PART 4---")
    s1 = "ALIGNMENT"
    s2 = "ALIGNNING"
    print(f'For strings {s1} and {s2} the minimum cost of an alignment is {part_4(s1,s2,2,-2,-1)}')


def part_5_test():
    print("---TEST FOR PART 5---")
    list = [5,9,7,2,4,1]

    print(f'Minimum number of operations needed to calculate the overall sum for the list {list} is {part_5(list)}')


def main():
    part_1_test()
    part_2_test()
    part_3_test()
    part_4_test()
    part_5_test()


if __name__ == '__main__':
    main()
