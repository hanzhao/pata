$rson = []
$lson = []
n = gets.chomp.to_i
$post = gets.chomp.split(" ").collect &:to_i
$inorder = gets.chomp.split(" ").collect &:to_i
$pr = n - 1
def solve(l, r)
    return nil if l > r
    thisroot = $post[$pr]
    $pr -= 1
    return thisroot if l == r
    index = $inorder.index thisroot
    $rson[thisroot] = solve(index + 1, r)
    $lson[thisroot] = solve(l, index - 1)
    return thisroot
end
queue = []
queue << solve(0, n - 1)
fir = true
while !queue.empty?
    now = queue.shift
    if fir
        print now
        fir = false
    else
        print " ", now
    end
    queue << $lson[now] if $lson[now]
    queue << $rson[now] if $rson[now]
end
puts

