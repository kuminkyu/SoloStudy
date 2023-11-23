def solution(nums):
    answer = int(len(nums))/2
    
    nums = set(nums)
    
    result = min(answer,len(nums))
    
    return result
