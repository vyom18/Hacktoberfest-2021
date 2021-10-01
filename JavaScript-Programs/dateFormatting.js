let date = new Date();
const dd = String(date.getDate()).padStart(2, "0");
const mm = String(date.getMonth() + 1).padStart(2, "0");
const yyyy = date.getFullYear();
// now we can format the date as we like
let today = yyyy + "." + mm + "." + dd;
console.log(today);
