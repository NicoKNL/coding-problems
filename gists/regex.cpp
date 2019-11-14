^   Start of string
        $   End of string
.   Wilcard, matches all but \n
|   Matches specific char or group on either side (a|b)
\   Used to escape special chars
        a   The char "a"
ab  The string "ab"

*       Match 0 or more
?       Match 0 or 1
+       Match 1 or more
{5}     Match exactly 5
{5, 10} Match 5 - 10

\s  Match whitespace char
\S  Match a non-whitespace char
\w  Match a word char
\W  Match a non-word char
\d  Match one digit
\D  Match one non-digit
[\b] A backspace char
\c  A control char

\n  Matches a newline
\t Matches a tab
\r Matches a carriage return

(xyz) grouping of chars
(?:xyz) Non-capturing group of chars
[xyz] Matches a range of chars (e.g. x or y or z)
[^xyz] Matches a character other than x or y or z
[a-q] Matches a char from within the range
[0-7] Matches a digit from within the range