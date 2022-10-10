UP = 0
DOWN = 1

def solve():
    n, p = map(int, input().split())

    ranges = []

    for _ in range(n):
        values = sorted(map(int, input().split()))
        # print(values)
        ranges.append((values[0], values[-1]))
    
    # print(ranges)
    table = [
        [0 for _ in range(n)], # UP
        [0 for _ in range(n)], # DOWN
    ]

    for i in range(n):
        # print("=" * 80)
        # print(table[0])
        # print(table[1])
        if i == 0:
            table[UP][0] = ranges[0][1]
            table[DOWN][0] = ranges[0][1] + (ranges[0][1] - ranges[0][0])
        
        else:
            prev_down_stop = ranges[i - 1][0]
            prev_up_stop = ranges[i - 1][1]
            # print(prev_down_stop, prev_up_stop)

            prev_up_cost = table[UP][i - 1]
            prev_down_cost = table[DOWN][i - 1]
            # print(prev_up_cost, prev_down_cost)

            current_range_cost = abs(ranges[i][0] - ranges[i][1])
            # print("range cost: ", current_range_cost)

            # GO UP NOW
            cost_to_go_up_if_went_up = current_range_cost + abs(prev_up_stop - ranges[i][0])
            cost_to_go_up_if_went_down = current_range_cost + abs(prev_down_stop - ranges[i][0])
            # print("UP if UP: ", cost_to_go_up_if_went_up)
            # print("UP if DOWN: ", cost_to_go_up_if_went_down)
            table[UP][i] = min(prev_up_cost + cost_to_go_up_if_went_up, prev_down_cost + cost_to_go_up_if_went_down)
            # print(table[0][i])
            

            # GO DOWN NOW
            cost_to_go_down_if_went_up = current_range_cost + abs(prev_up_stop - ranges[i][1])
            cost_to_go_down_if_went_down = current_range_cost + abs(prev_down_stop - ranges[i][1])
            # print("DOWN if UP: ", cost_to_go_down_if_went_up)
            # print("DOWN if DOWN: ", cost_to_go_down_if_went_down)
            table[DOWN][i] = min(prev_up_cost + cost_to_go_down_if_went_up, prev_down_cost + cost_to_go_down_if_went_down)
            # print(table[1][i])
    
    # print("table: ")
    # print(table[UP])
    # print(table[DOWN])
    return min(table[UP][n - 1], table[DOWN][n - 1])




if __name__ == "__main__":
    T = int(input())

    for i in range(1, T + 1):
        print(f"Case #{i}: {solve()}")
