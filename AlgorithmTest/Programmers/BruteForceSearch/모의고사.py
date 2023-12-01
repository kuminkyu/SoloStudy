def solution(answers):
    
    p1 = [1, 2, 3, 4, 5]
    p2 = [2, 1, 2, 3, 2, 4, 2, 5]
    p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    score = [0,0,0]
    result = []
    
    for idx, answer in enumerate(answers):
    	if answer == p1[idx%len(p1)]:
        	score[0] += 1
    	if answer == p2[idx%len(p2)]:
        	score[1] += 1
    	if answer == p3[idx%len(p3)]:
        	score[2] += 1
            
    for idx, s in enumerate(score):
    	if s == max(score):
        	result.append(idx+1)
    return result
