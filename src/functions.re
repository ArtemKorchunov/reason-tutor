/* Creating a parametrized type */
type universityStudent = {gpa: float};

type response('studentType) = {
  status: int,
  student: 'studentType
};

// let result: response(universityStudent) = fetchDataFromServer();

/* Functions */

(x) => x + 1;

let plusOne = x => x + 1;

plusOne(5);

let add = (x:int , y: int) : int => x + y;

add(1, 3);

let add = (x, y) => {
  let z = float_of_int(x);
  z +. y;
}

/* Curring */
let curring = add(2);
curring(3.6);

let numbers = [4, 11, 5];

let add = (x, y) => x + y;

List.map(x => add(4, x), numbers);
/* similar to above */
List.map(add(4), numbers);

/* ~ sign before a parameter */

let name = (~firstName, ~lastName) => firstName ++ " " ++ lastName;

name(~lastName="Doe")(~firstName="John");
name("John", "Doe");

let name = (~firstName as f, ~lastName as l) => f ++ " " ++ l;

let name = (~firstName, ~middleName="Francis", ~lastName) => {
  firstName ++ " " ++ middleName ++ " " ++ lastName;
};
/* let name: (~firstName: string, ~middleName: string=?, ~lastName: string) => string = <fun>; */

/* Reason # name(~firstName, ~middleName=?, ~lastName, ()) => {
  firstName ++ " " ++ middleName ++ " " ++ lastName;
}: */
/* Error: This expression has type option('a) but an expression was expected of type string */

let name = (~firstName, ~middleName=?, ~lastName, ()) => {
  switch middleName {
  | Some(value) => firstName ++ " " ++ value ++ " " ++ lastName
  | None => firstName ++ " Lala " ++ lastName
  };
};
name(~firstName="John", ~lastName="Doe", ());
/* - : string = "John Lala Doe" */
name(~firstName="John", ~middleName="Francis", ~lastName="Doe", ());
/* - : string = "John Francis Doe" */

let name = (~firstName, ~middleName="Francis", ~lastName, ()) => {
  firstName ++ " " ++ middleName ++ " " ++ lastName;
};
name(~firstName="John", ~lastName="Doe", ());
/* - : string = "John Francis Doe" */


let someName = Some("Francis");
name(~firstName="John", ~middleName=?someName, ~lastName="Doe", ());
/* similar to */
let middleName = Some("Francis");
name(~firstName="John", ~middleName?, ~lastName="Doe", ());
/* - : string = "John name Doe" */

let firstName = "John";
name(~firstName, ~middleName=?someName, ~lastName="Doe", ());

/* unit argument */

let hello = (()) => "Hello!";
/* similar to */
let hello = () => "Hello!";

List.map(item => item, [1, 2, 4]);
/* - : list(int) = [1, 2, 4] */

List.map(_item => 0, [1, 2, 4]);
/* similar */
List.map((_) => 0, [1, 2, 4]);
/* similar */
List.map(_ => 0, [1, 2, 4]);
/* [0, 0, 0] */


/* Chain functions */
let alert = "ALERT";

let info = String.capitalize(String.lowercase(alert));

let info = alert |> String.capitalize |> String.lowercase;

[1, 2, 3, 5]
  |> List.sort(compare)
  |> List.rev
  |> List.find(x => x > 4);

/*
  Recursive function (add `rec` before name of function to make it 
  available for inner context) 
*/

let rec addTillTen = (x) => {
  if (x < 10) {
    print_int(x);
    addTillTen(x + 1);
  }
}

let rec odd = x => ! even(x)
and even = x => {
  if (x === 0) {
    true;
  } else {
    odd(x - 1);
  }
}
