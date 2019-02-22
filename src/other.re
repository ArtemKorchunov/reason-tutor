/* Mutable let bindings ----------------------------------------------- */

let mutable_value = ref(6);
/* : ref(int) = {contents: 6} */
mutable_value := 8;
/* - : unit = () */
mutable_value;
/* : ref(int) = {contents: 8} */
mutable_value^;
/* 8 */

type game =
  | Menu
  | Playing
  | GameOver;

let store = ref(Menu);

store := GameOver;

store := Playing;


/* Exceptions ----------------------------------------------- */

List.find(x => x > 1, []);
/* Exception: Not_found. */

try (raise(Not_found)) {
| Not_found => "Oooops!"
};
/* - : string = "Oooops!" */

switch(List.find(x => x > 1, [])) {
| item => "Here is your item " ++ string_of_int(item)
| exception Not_found => "Something went wrong!"
};
/* - : string = "Something went wrong" */

switch(List.find(x => x > 1, [42])) {
  | item => "Here is your item " ++ string_of_int(item)
  | exception Not_found => "Something went wrong!"
  };
/* - : string = "Here is your item 42" */

/* Create own exceptions */

exception InputClosed(string);
/* exception InputClosed(string); */
raise(InputClosed("Error!"));
/* Exception: InputClosed("the stream has closed"). */


/* Loops ----------------------------------------------- */

for (x in 2 to 8) {
  print_int(x);
};
/* 2345678- : unit = () */

for (x in 8 downto 2) {
  print_int(x);
};

let x = ref(8);

while (x^ > 0) {
  print_int(x^);
  x := x^ - 1;
}