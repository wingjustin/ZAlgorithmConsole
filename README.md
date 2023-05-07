# ZAlgorithmConsole
<h3>Z Algorithm</h3>

<p>
Z Algorithm 重點在於重用已配對過的結果, 判斷之前結果是否適用。
<br><br>
使用Window Sliding Technique, 用L,R index 指定window位置, i 為當前元素index
<br><br>
<ul>
<li>1. 首先用朴素算法對當前元素與前綴配對計算字符的相同數目,並固定L,移動R至最後配對的index, 記錄計算結果並把i移動到下一個字符</li>
<br><br>
<li>2. 查看i是否在window內, 不在window內繼續用朴素算法, 在window內開始第3步</li>
<br><br>
<li>3. index 0至L 區間 映照 index L至R 區間, 移動 i 逐一判斷在[0,L]的之前結果是否適用
<br><br>
   ,判斷方法為在[0,L]的映照結果所表示的配對長度是否少於等於i至R的長度 (z[i - L] + 1) <= (R - i + 1)</li>
   <br><br>
<li>4. 適用就重用結果,不適用就更新window, 移動L到i位置,i重新用扑素算法計算
<br><br>
   ,不過因為i至R已經配對過,所以可以直接從R位置開始計算,數目由R-i+1開始加</li>
   <br><br>
   
   </ul>
</p>

<p>
因為會重用之前結果,外層循環線性遍歷一次,內層循環R每次都會右移一次,所以時間複雜度為 O(n)
</p>
