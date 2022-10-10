if __name__ == '__main__':
    scores_to_students = dict()
    scores = set()

    for _ in range(int(input())):
        name = input()
        score = float(input())
        scores.add(score)

        if score not in scores_to_students:
            scores_to_students[score] = [name]
        else:
            scores_to_students[score].append(name)

    target_score = sorted(list(scores))[1]
    names = sorted(scores_to_students[target_score])
    
    for name in names:
        print(name)