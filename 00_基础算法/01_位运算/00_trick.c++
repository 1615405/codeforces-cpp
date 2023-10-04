/* # 判断字符 c 是否为 "aeiouAEIOU" */
function<bool(char)> isVowel = [&](char ch) -> bool {
    ch &= 31;
    return ((2130466 >> ch) & 1) > 0;
};