def solution(arr):
    answer = []
    
    compare = arr[0]
    
    answer.append(compare)
    
    for i in arr:
        if compare != i:
            compare = i
            answer.append(i)
    
    return answer
