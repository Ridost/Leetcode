# 題目敘述
![圖片](https://github.com/Ridost/Leetcode_Practice/assets/35066190/d0bd42ca-9633-4405-89f9-af4f6e43196b)
# 解法
 - 設定兩個指標 start,end
 - 分別記錄單字的開頭以及結尾位置
 - 時間複雜度 O(N)
 - 空間複雜度 O(1)
### 字串切割 & 小寫轉換
讓end去掃描一遍 找到" "的位置停下 (空白的ASCII Code為32) 或是到達字串結尾也停下
掃描過程中使用tolower將每一個字母轉換成小寫
![圖片](https://github.com/Ridost/Leetcode_Practice/assets/35066190/39e41ddd-8df1-4b0b-94b9-5a9a5630ec61)

### 字首轉大寫
判斷(end-start)>=3 成立 則將start位置的字母轉大寫



