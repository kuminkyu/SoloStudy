def solution(clothes):
    
    #hash_map = {}

    #for clothe, type in clothes:
    #    hash_map[type] = hash_map.get(type, 0)+1
    #    print(type,hash_map.get(type, 0))

    #hash_map.get(type,0) # => Key에 해당하는 Value가 있으면 가져오고, 아닐 경우 0을 Default로 지정하여 사용
    #   
    #answer = 1
    #for type in hash_map:
    #    answer *= (hash_map[type]+1)
    #
    #return answer-1

    hash_map = {}
    
    for key, value in clothes:
        hash_map[value] = hash_map.get(value,0)+1
        print(value, hash_map.get(value,0))
        
    answer = 1 
    for value in hash_map:
        answer *= (hash_map[value]+1)
        
    return answer-1
