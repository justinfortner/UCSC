counter=0

for file in *; do
	if [ "$file" != "test.sh" ]; then
		while read line; do
			if ! ((counter % 2)); then
				echo "$file :$line"
			fi
			((counter++))
		done < "$file"
	fi
	counter=0
done
