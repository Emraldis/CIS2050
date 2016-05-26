Struct List{
	char * value
	List * next
}

List * createList(char * value){
	List = malloc(size(List))
	List->next = NULL
	List->value = value
	return(List)
}

List * destroyList(){
	return(NULL)
}

List * addToFront(List * element, List * list){
	element->next = list->next
	list->next = element
	return(list)
}

char * readFirstValue(List * list){
	return(list->value)
}

int getLength(List * list){
	int i = 0
	List * currentPos = list
	
	if(currentPost != NULL){
		while(currentPos->next != NULL){
			i++
			currentPost = currentPost->next
		}
	}
	
	return(i)
}

void printList(List * list){
	List * currentPost = list
	
	if(currentPost != NULL){
		while(currentPos->next != NULL){
			printf(list->value)
		}
	}
}

List * removeFromFront(List * list){

	if(list != NULL){
		if(list->next != NULL){
			return(list->next)
		}else{
			return(NULL)
		}
	}
	return(list)
}