/**
 * @param {string[][]} orders
 * @return {string[][]}
 */
var displayTable = function(orders) {
    let comp_set = new Map(), col = new Set();

    for (const [_, cntNum, items] of orders) {
        if (!comp_set.has(cntNum))
            comp_set.set(cntNum, new Map());
        col.add(items);
        comp_set.get(cntNum).set(items, 1 + (comp_set.get(cntNum).get(items) ?? 0));
    }

    col = [...col].sort();

    comp_set = [...comp_set]
        .sort(([ycomp_set], [xcomp_set]) => ycomp_set - xcomp_set)
        .map(([cntNum, foods]) => {
            const rows = col.map((col) => (foods.get(col) ?? 0).toString())
            rows.unshift(cntNum);
            return rows;
        });

    comp_set.unshift(["Table", ...col]);
    return comp_set;
};