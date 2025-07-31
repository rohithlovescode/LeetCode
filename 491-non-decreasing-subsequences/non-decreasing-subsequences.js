var findSubsequences = function(nums) {
    const res = new Set();

    function backtrack(index, path) {
        if (path.length >= 2) {
            res.add(path.join(","));
        }
        for (let i = index; i < nums.length; i++) {
            if (path.length === 0 || nums[i] >= path[path.length - 1]) {
                backtrack(i + 1, [...path, nums[i]]);
            }
        }
    }

    backtrack(0, []);
    return [...res].map(str => str.split(',').map(Number));
};