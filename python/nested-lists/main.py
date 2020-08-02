# https://www.hackerrank.com/challenges/nested-list/problem

if __name__ == '__main__':
    
    l = []
    scores = set()
    answer = []
    
    for _ in range(int(input())):
        name = input()
        score = float(input())
        l.append( [name, score] )
        scores.add(score)
    
    l_scores = sorted(scores)
    second_lowest = l_scores[1]

    # get the second lowest score

    for name,score in l:
        if score == second_lowest:
            answer.append(name)

    for name in sorted(answer):
        print(name)

    