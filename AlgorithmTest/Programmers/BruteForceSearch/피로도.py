from itertools import permutations

def solution(k, dungeons):
    cnt_list = []
    
    for perm in permutations(range(len(dungeons)),len(dungeons)):
        temp = k
        cnt = 0
        
        # print(perm)
        
        for i in perm:
            need, use = dungeons[i]
            # print(need,use)
            
            if temp>=need:
                # print('##',temp,need)
                cnt += 1
                temp -= use
        
        # print(cnt)
        
        cnt_list.append(cnt)
    
    return max(cnt_list)
