def solution(participant, completion):
    
    #participant.sort()
    #completion.sort()
    
    #for a,b in zip(participant, completion):
    #    if a!=b:
    #        return a
        
    #return participant[-1]
    
    hash ={}
    for i in participant:
        if i in hash:
            hash[i] += 1
        else:
            hash[i] = 1
            
    for i in completion:
        if hash[i] == 1:
            del hash[i]
        else:
            hash[i] -= 1
            
    answer = list(hash.keys())[0]
    return answer
        
