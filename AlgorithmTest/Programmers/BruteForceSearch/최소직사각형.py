def solution(sizes):
    
    x = []
    y = []
    for i in sizes:
        i.sort()
        x.append(i[0])
        y.append(i[1])
    
    x.sort()
    y.sort()
    
    answer = x[-1] * y[-1]
    return answer
