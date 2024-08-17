func abs(num int) int {
    if num < 0 {
        return num * -1
    }
    return num
}

func maxPoints(points [][]int) int64 {
    scores := points[0]
    var next_scores []int
    next_scores = append(next_scores, scores...)

    for i := 1; i < len(points); i++ {
        for ii, num := range points[i] {
            best := 0
            
            for iii, prev_num := range scores {
                best = max(best, num + prev_num - abs(iii - ii))
            }

            next_scores[ii] = best
        }
        copy(scores, next_scores)
    }

    return int64(slices.Max(scores))
}
