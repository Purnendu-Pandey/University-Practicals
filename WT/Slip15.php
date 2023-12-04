<!--
Q.1) Design a form to accept string from the user and perform the following operations
a. To select first 5 words from the string
b. Convert the given string to lowercase and then to Title case.
c. Pad the given string with “*” from left and right both the sides. 
d. Remove the leading whitespaces from the given string. 
e. Find the reverse of given string
-->

<!-- HTML FILE -->
<html>
   <body>
      <form action="setA2.php" method="GET">
         Enter String : <input type="text" name="n1"/>
         <br />
         <br />
         <input type="radio" name="op" value="1"/>
         1.To select first 5 words of string...
         <br />
         <input type="radio" name="op" value="2"/>
         2.string to lowrrcase and then titlecase...
         <br />
         <input type="radio" name="op" value="3"/>
         3.pad string from both side with *....
         <br/>
         <input type="radio" name="op" value="4"/>
         4.remove whitespace from begining...
         <br>
         <input type="radio" name="op" value="5"/>
         5.find rev of given string ....
         <br/>
         <br/>
         <input type="submit"/>
      </form>
   </body>
</html>

<!-- PHP FILE -->
<?php
$str = $_GET["n1"];
$ch = $_GET["op"];
echo "Entered string is : " .$str;
echo "<br>";
echo "selected option is : ".$ch;
echo "<br>";

switch ($ch)
{
    case 1:
        length($str);
        break;
    case 2:
        count_vowels($str);
        break;
    case 3:
        lowr_case($str);
        break;
    case 4:
        pad($str);
        break;
    case 5:
        rem_whit_space($str);
        break;
    case 6:
        rev($str);
        break;
}

function length($str)
{
    $len = strlen($str);
    $cnt = 0;
    for ($i = 0; $i < $len; $i++)
        $cnt++;
    echo "length of string is : " . $cnt;
}

echo "<br>";
function count_vowels($str)
{
    $cn = 0;
    $len = strlen($str);
    for ($i = 0; $i < $len; $i++)
        if ($str[$i] == "a" || $str[$i] == "e" || $str[$i] == "i" || $str[$i] == "o" || $str[$i] == "u")
            $cn++;
    echo "vowel count is : " . $cn;
}

echo "<br>";

function lowr_case($str)
{
    $st = strtolower($str);
    echo " string in lowercase is :" . $st;
    echo "<br>";
    $s = ucwords($str);
    echo " Titlecase string is " . $s;
}

function rev($str)
{
    $str = strrev($str);
    echo " Reverse string is : " . $str;
}

function pad($str)
{
    $p = str_pad($str, 20, "*", STR_PAD_BOTH);
    echo " Paded string with * is : " . $p;
}

function rem_whit_space($str)
{
    $k = str_replace(" ", "", $str);
    echo "String without whit space removing from start is : " . $str;
    echo "<br>";
    echo "String after removing white space from start is : " . $k;
}
?>