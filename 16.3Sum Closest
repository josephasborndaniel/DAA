def threeSumClosest(nums, target):
    nums.sort()  # Sort the array
    closest_sum = float('inf')  # Initialize closest sum to a very large number
    
    for i in range(len(nums) - 2):
        left, right = i + 1, len(nums) - 1
        
        while left < right:
            current_sum = nums[i] + nums[left] + nums[right]
            
            # If the current sum is closer to the target, update the closest sum
            if abs(current_sum - target) < abs(closest_sum - target):
                closest_sum = current_sum
            
            # Adjust the pointers based on the comparison of current sum and target
            if current_sum < target:
                left += 1  # Increase the sum by moving the left pointer to the right
            elif current_sum > target:
                right -= 1  # Decrease the sum by moving the right pointer to the left
            else:
                # If the current sum is exactly equal to the target, return the current sum
                return current_sum
    
    return closest_sum
