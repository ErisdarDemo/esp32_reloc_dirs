@brief      cmake example
@details    x
@auth       Justin Reina
@date       3/15/25


@section    Change build directory name
	
	• Simple - 
	
		mkdir out; cmake -B out

	But ESP-IDF still leaves a build dir, no matter what
	
	
	• So instead
	
		Compile project then manually relocate for storage

