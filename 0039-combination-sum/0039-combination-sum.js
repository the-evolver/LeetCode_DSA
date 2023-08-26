/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
function combinationSum(candidates, target) {
   
    var res = [];
	function dfs(path, sum, last) {
        if (sum === target) {
             res.push(path);
             return;
        }
       for (var i = last; i < candidates.length; i++) {
           
            if (sum + candidates[i] <= target) {
               dfs([...path, candidates[i]], sum + candidates[i], i);
            }
        }
    }
	candidates.sort(function (a, b) {
        return a - b;
    });
	
    dfs([], 0, 0);
	return res;
}
