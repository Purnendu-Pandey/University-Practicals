<!--
Q.1) Write a PHP script for the following: Design a form having a text box and a drop down list 
containing any 3 separators(e.g. #, |, %, @, ! or comma) accept a strings from the user and also a 
separator. 
a. Split the string into separate words using the given separator. 
b. Replace all the occurrences of separator in the given string with some other separator. 
c. Find the last word in the given string.
-->

<!--HTML FILE-->
<html >
   <body>
      <form action="B2.php" method="GET">
         Enter  String : <input type="text" name="n1" />
         <br />
         <br />
         Enter seperator : 
         <select name="sep">
            <option>select any one </option>
            <option valuse=",">,</option>
            <option value="#">#</option>
            <option value="$">$</option>
            <option value="%">%</option>
         </select>
         <br><br>
         <input type="radio" name="op" value="1" />
         1.split the  string....
         <br />
         <input type="radio" name="op" value="2" />
         2.replace occurrence of sep with other sep....
         <br />
         <input type="radio" name="op" value="3" />
         3.Find last word in string...
         <br />
         <br />
         <input type="submit" />
      </form>
   </body>
</html>

<!-- PHP FILE -->
<?php
$str1=$_GET["n1"];
$str2=$_GET["sep"];
$ch=$_GET["op"];
echo "Entered string is : " .$str1;
echo "<br>";
echo "Entered separator is : ".$str2;
echo "<br>";
echo "selected option is : ".$ch;
echo "<br>";

switch ($ch) 
{
    case 1:
        split_str($str2, $str1);
        break;
    case 2:
        sep_replc($str2, $str1);
        break;
    case 3:
        last_occur($str1, $str2);
        break;
}

function split_str($str2, $str1)
{
    $st=explode($str2, $str1);
    print_r($st);
}
echo "<br>";

function sep_replc($str2, $str1)
{
    $s=str_replace($str2,"*",$str1);
    echo "New string is : ".$s;
}
echo "<br>";

function last_occur($str1, $str2)
{
    $k=strrchr($str1, $str2);
    echo "Last word is :" .$k;
}
?>