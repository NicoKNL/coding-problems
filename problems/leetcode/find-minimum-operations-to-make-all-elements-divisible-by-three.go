func minimumOperations(nums []int) int {
    total := 0
    for _, num := range nums {
        if num % 3 > 0 {
            total += 1
        }
    }
    return total
}
