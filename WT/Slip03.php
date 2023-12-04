<!--
Q.1) Write a program using html with following CSS specifications- [15]
i. The background colour of the company name should be in green.
ii. The text colour of the company name should be red.
iii. The heading should be large –with font ''comic sans ms''
iv. The description of the company should be displayed in blue color in a paragraph.
-->

<html>
<head>
    <style>
        .cpn {
            background: green;
            color: red;
            display: flex;
            justify-content: center;
            border-radius: 25% 25%;
            font-family: comic sans ms;
        }
        p{
            color: blue;
        }
    </style>
</head>

<body>
    <h1 class="cpn">Sankalp Enterprises</h1>
    <p>This Company is all About Transporting Fruits and Vegetable</p>
</body>
</html>