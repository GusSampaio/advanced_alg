INT_MAX = 500
def search_best_price(ac_day, day_x, day_y, day_z):
    cost1, cost2, cost3 = INT_MAX, INT_MAX, INT_MAX
    while (ac_day not in days and ac_day <= days[amount_days-1]):  
        ac_day += 1

    if ac_day > days[amount_days-1]:
        return 0

    if memo[ac_day-1] != 0:
        return memo[ac_day-1]
    else: 
        cost1 = day_x + search_best_price(ac_day + 1, day_x, day_y, day_z)
        cost2 = day_y + search_best_price(ac_day + 7, day_x, day_y, day_z)
        cost3 = day_z + search_best_price(ac_day + 30, day_x, day_y, day_z) 
        
        memo[ac_day-1] = min(cost1, cost2, cost3)
        return memo[ac_day-1]

amount_days = int(input())
# day_x -> 1 day // day_y -> 7 days // day_z -> 30 days
day_x, day_y, day_z = [int(i) for i in input().split()]
days = [int(i) for i in input().split()]
memo = [0]*days[amount_days-1]

print(search_best_price(0,day_x, day_y, day_z))