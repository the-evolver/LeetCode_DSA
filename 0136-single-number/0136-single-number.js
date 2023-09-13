/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    
    return nums.reduce(function(acc,curr){
        return acc ^ curr;
    },0)
    
};