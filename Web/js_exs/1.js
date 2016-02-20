/*
var str = "#";
for (var i = 0; i < 7; i++) {
	console.log(str);
	str += "#";
}

//FizzBuzz
for (var i = 1; i <= 100; i++) {
	var str = "";
	if (i % 3 == 0) {
		str += "Fizz";
	} 
	if (i % 5 == 0) {
		str += "Buzz";
	}
	if (i % 3 == 0 || i % 5 == 0){
		console.log(str);
	} else {
		console.log(i);
	}
}

for (var i = 0; i < 8; i++) {
	var str = "";
	if (i % 2 == 1) {
		str += " "
	}
	for (var j = 0; j < 8; j++) {
		if (j % 2 == 1) {
			str += " ";
		} else {
			str += "#";
		}
	}
	if (i % 2 == 0) {
		str += " "
	}
	console.log(str);
}



function multiplier(factor) {
  return function(number) {
    return number * factor;
  };
}

var twice = multiplier(2);
console.log(twice(5));
// → 10



function min(a, b) {
	if (a <= b) {
		return a;
	} else {
		return b;
	}
}
console.log(min(0, -10));


function isEven(x) {
	if (x == 0) {
		return true;
	}
	if (x == 1) {
		return false;
	}
	return isEven(x - 2);
}
console.log(isEven(-1));


function range(begin, end) {
	ran = [];
	for (var i = begin; i <= end; i++) {
		ran.push(i);
	}
	return ran;
}
console.log(range(1, 10));




function average(array) {
  function plus(a, b) { return a + b; }
  return array.reduce(plus) / array.length;
}
function age(p) { return p.died - p.born; }
function male(p) { return p.sex == "m"; }
function female(p) { return p.sex == "f"; }

console.log(average(ancestry.filter(male).map(age)));
// → 61.67
console.log(average(ancestry.filter(female).map(age)));
// → 54.56





var theSet = ["Carel Haverbeke", "Maria van Brussel",
              "Donald Duck"];
function isInSet(set, person) {
  return set.indexOf(person.name) > -1;
}

console.log(ancestry.filter(function(person) {
  return isInSet(theSet, person);
}));
// → [{name: "Maria van Brussel", …},
//    {name: "Carel Haverbeke", …}]
console.log(ancestry.filter(isInSet.bind(null, theSet)));
// → … тот же результат


*/

/*У массивов есть несколько полезных методов высшего порядка – forEach, 
чтобы сделать что-то с каждым элементом, filter – чтобы построить новый массив,
 где некоторые значения отфильтрованы, 
 map – чтобы построить новый массив, каждый элемент которого пропущен через функцию, 
 reduce – для комбинации всех элементов массива в одно значение.

У функций есть метод apply для передачи им аргументов в виде массива.
 Также у них есть метод bind для создания копии функции с частично заданными аргументами.
*/ 

/*

var arrays = [[1, 2, 3], [4, 5], [6]];
console.log(arrays.reduce(function(a, b) {return a.concat(b);}));


function every(array, pred) {
	return array.map(pred).reduce(function(a, b) {return a && b;});
}
function some(array, pred) {
	return array.map(pred).reduce(function(a, b) {return a || b;});
}
console.log(some([2, 3, 4], isNaN));


speak.apply(fatRabbit, ["Отрыжка!"]);
// → А толстый кролик говорит 'Отрыжка!'
speak.call({type: "старый"}, "О, господи.");
// → А старый кролик говорит 'О, господи.'



\d – любая цифра
\w – алфавитно-цифровой символ
\s – пробельный символ (пробел, табуляция, перевод строки, и т.п.)
\D – не цифра
\W – не алфавитно-цифровой символ
\S – не пробельный символ
. – любой символ, кроме перевода строки


*/
addEventListener("click", function() {
    console.log("Щёлк!");
  });