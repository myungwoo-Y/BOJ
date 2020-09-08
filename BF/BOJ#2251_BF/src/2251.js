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
let limit;
let m = new Map();
let ans = new Set();
const getKey = (arr) => {
    let key = '';
    for(let i = 0; i < arr.length; i++)
        key += arr[i];
    return key;
}

const search = (arr, key) => {
    if(m[key] !== undefined)
        return;
    m[key] = true;
    for (let i = 0; i < arr.length; i++){
        for (let j = 0; j < arr.length; j++){
            if(i === j ||arr[j] === limit[j] || arr[i] === 0)
                continue
            else{
                let newArr = [...arr];
                let differ = limit[j]-arr[j];
                let canAdd = limit[j]-arr[j] < arr[i] ? limit[j]-arr[j] : arr[i];
                newArr[i] -= canAdd;
                newArr[j] += canAdd;
                if(newArr[j] === limit[j] || newArr[i] == 0){
                    search(newArr, getKey(newArr));
                    if(newArr[0] == 0){
                        ans.add(newArr[2]);
                    }
                }
            }
        }
    }

}

rl.on('line', (line) => {
    input.push(line.trim());
}).on('close', () => {
    let inputLength = input.length;

    limit = input.shift().split(' ').map(a => parseInt(a));
    let arr = [...limit];
    arr[0] = 0;
    arr[1] = 0;
    search(arr, getKey(arr));

    ans = [...ans].sort((a, b) => {
        return a-b;
    })

    console.log(...ans)

    process.exit();
});