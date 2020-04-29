const readline = require('readline');
const fs = require('fs');
const path = require("path");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


// const rl = readline.createInterface({
//     input: fs.createReadStream(path.resolve(__dirname, "in.txt")),
// });

let input = [];
let rowS, colS, k;
let table = [];
let targetWord;
let ans = 0;
let visited = [];
let cache = [];
let directions = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
]
const backTracking = (r, c, length) => {
    if(table[r][c] !== targetWord[length]){
        return 0;
    }
    if(length === targetWord.length-1){
        return 1;
    }

    if(cache[r][c][length] !== -1)
        return cache[r][c][length];

    cache[r][c][length] = 0;
    for(let dir = 0; dir < 4; dir++){
        for (let d = 1; d <= k; d++){
            let newR = r+directions[dir][0]*d;
            let newC = c+directions[dir][1]*d;
            if(newR < 0 || newR >= rowS || newC < 0 || newC >= colS){
                continue;
            }else{
                cache[r][c][length] += backTracking(newR, newC, length+1);
            }
        }
    }
    return cache[r][c][length];
}

rl.on('line', (line) => {
    input.push(line.trim());
}).on('close', () => {
    [rowS, colS, k] = input.shift().split(' ').map(e => parseInt(e));
    for(let i = 0; i < rowS; i++){
        table.push([]);
        let inputStr = input.shift();
        for(let j = 0; j < colS; j++){
            table[i].push(inputStr[j]);
        }
    }

    for(let i = 0; i < rowS; i++){
        visited.push([]);
        for(let j = 0; j < colS; j++){
            visited[i].push(false);
        }
    }

    targetWord = input.shift();
    for(let i = 0; i < rowS; i++){
        let arr = Array.from({length:colS},
            (e, i)=> Array.from({length:targetWord.length},
                (e, i)=> -1));
        cache.push(arr);
    }
    for(let i = 0; i < rowS; i++){
        for(let j = 0; j < colS; j++){
            ans += backTracking(i,j,0);
        }
    }
    console.log(ans);
    process.exit();
});