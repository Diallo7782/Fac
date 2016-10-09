(**Exercice1**)

let facture = (function p ->
									function q -> 
										let com = p *. (float_of_int q) in 
											if com >= 100. then
												com
											else 
												let port = 0.10 *. com in
											if port >= 2. then
												com +. port
											else
												com +. 2.
							);;
facture 35. 2;;

(**Exercice2**)

let int_vers_hexa = function n ->
	if n >= 0 && n <= 9 then
		(char_of_int ((int_of_char '0') + n))
	else
		if n >= 10 && n <= 15 then
			(char_of_int ((int_of_char 'A') + n - 10))
		else 
			failwith "Donn�e incorrecte";;

int_vers_hexa 15;;

let hexa_vers_int = function c ->
	if c >= '0' && c <= '9' then
		(int_of_char c) - (int_of_char '0')
	else
		if c >= 'A' && c <= 'F' then
			(int_of_char c) - (int_of_char 'A') + 10
		else 
			failwith "Donnee incorrecte";;

hexa_vers_int 'D' ;;

(**Exercice 3**)

let premier = function p ->
	if (String.length p) != 0 then
		(String.get p 0)
	else
		failwith "Il n' y a pas de chaine";;

premier "diallo";;

let sauf_premier = function sp ->
	if (String.length sp) != 0 then
		(String.sub sp 1 ((String.length sp) - 1))
	else
		failwith "Il n' y a pas de chaine";;

sauf_premier "Thierno";;

let dernier = function d ->
	if (String.length d) != 0 then
		(String.get d ((String.length d) - 1))
	else
		failwith "Il n' y a pas de chaine";;

dernier "Souleymane";;

let sauf_dernier = function sd ->
	if (String.length sd) != 0 then
		(String.sub sd 0 ((String.length sd) - 1))
	else
		failwith "Il n' y a pas de chaine";;

sauf_dernier "Rouen";;

let echange = function ch ->
	if (String.length ch) = 0 then
		ch 
	else
		(Char.escaped (dernier ch))^(sauf_premier (sauf_dernier ch))^(Char.escaped (premier ch));;

echange "halima";;

let milieu = function mi ->
	if (String.length mi) != 0 then
		(String.get mi ((String.length mi) / 2))
	else
		failwith "Il n' y a pas de chaine";;

milieu "thierno";;

(**Exercice4**)

let inf = function (a, b, c) -> 
						function (a', b', c') ->
							if (c < c' || (c == c' && b < b') || (c == c' && b == b' && a < a')) then
								true
							else
								false;;

inf (1, 5, 6) (4, 5, 6);;
(**Execice5**)

let aire_couronne = function r1 ->
											function r2 ->
												let pi = atan 1. *. 4. in
												let aire = pi *. (r2**2. -. r1**2.) in 
												if(r1 < r2) then 
													aire
												else
													failwith "r2 doit etre plus grand que r1";;

aire_couronne 5. 6.;;

(**Exercice 6**)

let compose f g = 
	function x -> (f (g x));;

let carre x = x * x and double x = x + x;;

let appli = (compose double carre);;

appli 4;;

(**TP3 Suite**)

(**Exercice 1**)

let concat = function mot1 ->
								function mot2 ->
									if (String.length mot1) == 0 || (String.length mot1) == 1 then
										(String.sub mot2 ((String.length mot2) / 2) ((String.length mot2) - 1))
									else if (String.length mot2) == 0 || (String.length mot2) == 1 then
										(String.sub mot1 0 ((String.length mot1) / 2))
									else
										(String.sub mot1 0 ((String.length mot1) / 2))^(String.sub mot2 ((String.length mot2) / 2) ((String.length mot2) / 2));;
									
concat "thiernos" "diallo";;			

(**Exercice 2**)

let bissextile = function a ->
										if (a mod 4 == 0 && a mod 100 != 0) || a mod 400 == 0 then
											"L'annee est bissextile"
										else
											"L'annee n'est pas bisextile";;	

bissextile 2000;;	

let jour_noel a = 
	let n = ((a - 1900) + (a / 4 - 1900 / 4) - (a / 100 - 1900 / 100) + (a / 400 - 1900 / 400)) mod 7
		in match n with
		| 0 -> "Lundi"
		| 1 -> "Mardi"
		| 2 -> "Mercredi"
		| 3 -> "Jeudi"
		| 4 -> "Vendredi"
		| 5 -> "Samedi"
		| 6 -> "Dimanche"
		| _ -> failwith "Erreur";;

jour_noel 2000;; 	

(**Exercice 3**)

let arrondi1 = function x ->
									if (ceil x) -. x > 0.5 then
										(floor x)
									else 
										(ceil x);;

arrondi1 3.25;;

let arrondi2 = function x ->
									if (ceil x) -. x > 0.25 then
										if (ceil x) -. x < 0.75 then
											(floor x) +. 0.5
										else
											(floor x)
									else
										(ceil x);;

arrondi2 1.2;;

let arr_a_n =
	fun x y ->
			float_of_int (int_of_float( x*.10.**(float_of_int y))) /. (10.**(float_of_int y))
;;
(arr_a_n 12.23427 4);;

(**Exercice 4**)

let curry f = fun x y -> f(x, y);;
let modul(x, y) = x * x + y * y;;
let modul2 = curry modul;;

modul2 3 4;;
		
												