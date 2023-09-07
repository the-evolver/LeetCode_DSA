/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let lastlen = 0;
    s.split(' ').forEach(function(currEl){
         lastlen = currEl.length > 0 ? currEl.length :lastlen;
        
    })
  return lastlen;  
};