function getInt() {
    let i = Number(0);
    return ()=>{ return ++i; };
};

let g = getInt();
for(let i=0; i<5; ++i) {
    console.log(g())
}