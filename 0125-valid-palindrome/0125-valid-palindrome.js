/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    
    s = s.toLowerCase();
    const str = s.split('').filter(function(curr){
        if((curr.charCodeAt(0) >= 97 && curr.charCodeAt(0) <= 122  ) || (curr.charCodeAt(0) >= 48 && curr.charCodeAt(0) <= 57 ))
            return true;
        return false;
    });
    console.log(str);
    
    for(let i = 0 , j = str.length - 1; i < j ; i++,j--){
        if(str[i] !== str[j])
            return false;
    }
    return true;
    
};