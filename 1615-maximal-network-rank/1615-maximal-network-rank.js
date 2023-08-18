/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var maximalNetworkRank = function(n, roads) {
    let maxi = 0;
    const complete_map = [];
    const score = [];
    
    for (let i = 0; i < n; i++) {
        complete_map.push(Array(n).fill(0));
    }
    
    for (const [from, to] of roads) {
        complete_map[from][to] = 1;
        complete_map[to][from] = 1;
    }

    for (let i = 0; i < n; i++) {
        score[i] = complete_map[i].filter(x => x > 0).length;
    }

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const res = score[i] + score[j] + (complete_map[i][j] > 0 ? -1 : 0);
            maxi = Math.max(maxi, res);
        }
    }

    return maxi;
};