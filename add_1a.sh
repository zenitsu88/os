cho "Enter your choice"
echo "1: Create new file"
echo "2: Work in Existing file"
read filech

	echo "Enter name for file: "
	read file_name
	echo "------ $file_name"

if [ $filech -eq 1 ]
then 
	touch $file_name
	echo "File created Successfully"
	
fi
	
ch=0
	
while [ $ch -ne 6 ]
do

	echo "Enter your choice: "
	echo "1: Insert data: "
	echo "2: Search for record "
	echo "3: Update data: "
	echo "4: Delete record "
	echo "5: View Book"
	echo "6: Exit"
	read ch
	# echo " CHHHHHHHHHHHHHHH $ch"

	case $ch in
	1) ch_1=1
	while [ $ch_1 -eq 1 ]
	   do
		
		echo "Enter employee_id	name	mobile_no	city"
		read emp_id emp_name emp_mno emp_city
		
		if [ ${#emp_mno} -ne 10 ]
		then
			echo "Enter valid mobile no.: "
			read emp_mno
		fi	
		
		# echo "Id   $emp_id"
		# echo "Name $emp_name "
		# echo "Mobile $emp_mno"
		# echo "City $emp_city"
		
		arr[0]=$emp_id
		arr[1]=$emp_name
		arr[2]=$emp_mno
		arr[3]=$emp_city
		
		#cat ${arr[@]} > $file_name
		echo " ${arr[@]} " | cat >> $file_name
		
		echo "Do you want to insert more records? "
		echo "1) Yes "
		echo "2) No "
		read ch_1
		
	   done		
	;;
	
	2)echo "Enter name or employee id to search record: "
		read search
		grep $search $file_name
		if [ $? -eq 0 ]
		then
			echo "Record Found"
		else
			echo "Record Not Found"
		fi		
		;;
		
	3) echo "Enter the Employee id to update the record"
		read update
		echo "Enter choice to update"
		echo "1) Mobile no."
		echo "2) City "
		echo "3) Both"
		read upch
		
		case $upch in 
		1) echo "Enter new mobile no. "
			read newmob
			
			if [ ${#newmob} -ne 10 ]
			then
				echo "Enter valid mobile no.: "
				read newmob
			fi
			
			grep $update $file_name > temp 
			temp1=` cut -f 4 -d\  temp `
			sed -i 's/'$temp1'/'$newmob'/' $file_name
			
		;;
		2) echo "Enter new city name "
			read newcity
			grep $update $file_name > temp 
			temp1=` cut -f 5 -d\  temp`
			sed -i 's/'$temp1'/'$newcity'/' $file_name
		;;
		3) echo "Enter new city name "
			read newcity
			grep $update $file_name > temp 
			temp1=` cat temp | cut -f 5 -d\ `
			sed -i 's/'$temp1'/'$newcity'/' $file_name
			 
			 
			echo "Enter new mobile no. "
			read newmob
			
			if [ ${#newmob} -ne 10 ]
			then
				echo "Enter valid mobile no.: "
				read newmob
			fi
			
			grep $update $file_name > temp 
			temp2=` cat temp | cut -f 4 -d\ `
			sed -i 's/'$temp2'/'$newmob'/' $file_name
		;;
		*) echo "Invalid Input!!"		
		
		
		esac
	;;

	4) echo "Enter Employee id to delete the record: "
		read del
		sed -i '/'$del'/d' $file_name
		#temp > Demo
		if [ $? -eq 0 ]
		then
			echo "Record Deleted"
		else
			echo "Record Not Deleted"
		fi
		;;

	
	5) cat $file_name
		;;
	
	6);;
		
	*) echo "Invalid Input"
	;;
	
	esac	 	

done
