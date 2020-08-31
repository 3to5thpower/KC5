# KC5
Kansai Computer Circle Conference Calculator Compiler

RPN(逆ポーランド記法)で与えられた式を計算するx64のアセンブリを吐きます。

## 導入
まずcloneします  
`git clone https://github.com/3to5thpower/KC5.git`

次にcloneしたリポジトリのディレクトリに入り、ビルドします。  
### Linuxの場合
`cd KC5 && make`
### macの場合
`cd KC5 && make kc5-mac`  

## 使い方
kc5はコマンドライン引数として四則演算を含むRPN式の文字列を解釈し、標準出力にアセンブリを出力します。 
macの場合はバイナリ名がkc5-macになっているので適宜置き換えて読んでください。  
  
```
> ./kc5 '1 2 +'

...
```

したがってこれを一時ファイルに保存し、それをアセンブルした後実行することで、終了ステータスに計算結果が格納されます。
```
> ./kc5 '1 2 +' > tmp.s
> gcc tmp.s -o tmp
> ./tmp
> echo $?
3
```
test.shにテスト用の計算式を追加することもできます。  
test.shは`make test`で実行されます。(macの場合は`make test-mac`で実行されます。)  
test.shの末尾に`assert n '<計算式>'`を追加すると、第二引数の式をコンパイル・実行し、その結果を第一引数の数値と比較します。



