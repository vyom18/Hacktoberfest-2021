// this is the codewars challenge
/* If we list all the natural numbers below 10 that are multiples of 3 or 5,
  we get 3, 5, 6 and 9. The sum of these multiples is 23.*/
/* Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in. 
Additionally, if the number is negative, return 0(for languages that do have them).*/
// Note: If the number is a multiple of both 3 and 5, only count it once.
function solution(number) {
	const numbers = [];
	for (i = 1; i < number; i++) {
		numbers.push(i);
	}
	const filteredNumbers = numbers.filter((num) => {
		return num % 3 === 0 || num % 5 === 0;
	});
	let sum = 0;
	filteredNumbers.forEach((num) => (sum = sum + num));
	return sum;
}
