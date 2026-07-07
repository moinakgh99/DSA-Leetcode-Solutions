/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    if(this.length == 0) return -1;
    
    let n = this.length;
    return this[n-1];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */