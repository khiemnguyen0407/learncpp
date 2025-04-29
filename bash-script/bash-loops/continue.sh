#!/bash/bin

for i in {1..10}
do
    if [[ $(($i % 2)) -eq 0 ]]
    then
        echo "Skipping even number"
        continue
    fi
    echo "i is equal to $i"
done

echo "======================"
printf "\n"

for j in {1..10}
do 
    if [[ $(($j % 2)) -eq 1 ]]
    then
        echo "Skipping odd number"
        continue
    fi
    echo "j is equal to $j"
done
