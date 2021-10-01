// Codewars Challenge
/* Check to see if a string has the same amount of 'x's and 'o's.
 The method must return a boolean and be case insensitive.The string can contain any char.*/

function XO(str) {
	//code here
	const arr = str.toUpperCase().split("");
	const filteredArr = arr.filter((elm) => elm === "X");
	const anotherFilteredArr = arr.filter((elm) => elm === "O");
	if (filteredArr.length === anotherFilteredArr.length) {
		return true;
	}
	return false;
}
