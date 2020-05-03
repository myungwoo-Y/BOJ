const readline = require('readline');
const fs = require('fs');
const path = require("path");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// const rl = readline.createInterface({
//     input: fs.createReadStream(path.resolve(__dirname, "./in.txt")),
// });

const getArrayFromLine = (line) => {
    return line.split(' ').map(e => parseInt(e));
}

let table = [];
let input = [];
let colS = 0, rowS = 0;

const getVisitedArray = () => {
    let visited = [];
    for(let i = 0; i < rowS; i++){
        visited.push(new Array(colS).fill(false));
    }
    return visited;
}

const directions = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
    [1, 1],
    [1, -1],
    [-1, 1],
    [-1, -1],
]

const indexCheck = (r, c) => {
    if(r < 0 || r >= rowS || c < 0 || c >= colS)
        return false
    else
        return true;
}

const bfs = (r, c, label) => {
    let q = [];
    let visited = getVisitedArray();
    q.push([r, c]);
    visited[r][c] = true;
    table[r][c] = label;

    while(q.length !== 0){
        let [curR, curC] = q.shift();
        for(let dir = 0; dir < directions.length; dir++){
            let newR = curR + directions[dir][0];
            let newC = curC + directions[dir][1];

            if(indexCheck(newR, newC) && !visited[newR][newC] && table[newR][newC] === 1){
                table[newR][newC] = label;
                visited[newR][newC] = true;
                q.push([newR, newC]);
            }
        }
    }
}

rl.on('line', (line) => {
    input.push(line)
}).on('close', () => {

    while(true){
        [colS, rowS] = getArrayFromLine(input.shift());
        if(colS === 0 && rowS === 0)
            break;
        table = [];
        for (let i = 0; i < rowS; i++){
            table.push(getArrayFromLine(input.shift()));
        }
        let label = 2;
        for(let i = 0; i < rowS; i++){
            for(let j = 0; j < colS; j++){
                if(table[i][j] === 1){
                    bfs(i, j, label);
                    label++;
                }
            }
        }
        console.log(label-2);
    }

    process.exit();
});