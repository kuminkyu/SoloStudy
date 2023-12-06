def solution(phone_book):
    
    #cnt = 0
    #for i in phone_book:
    #    for j in phone_book:
    #        if i != j:
    #            if j.find(i) != -1:
    #                k = j[0:len(i)]
    #                if k == i:
    #                    cnt += 1
    #                    print(i)
    #
    #if cnt > 0:
    #    return False
    #else:
    #    return True
    
    hash = {}
    
    for i in phone_book:
        hash[i] = 1
    
    for i in phone_book:
        jo = ""
        for num in i:
            jo += num
            
            if jo in hash and jo != i:
                print(jo,hash,i)
                return False
    
    return True
