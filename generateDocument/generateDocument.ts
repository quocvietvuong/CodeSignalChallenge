function generateDocument(characters: string, document: string) {
    let charactersMap = new Map<string, number>([]);
    let documentMap = new Map<string, number>([]);
    
    for (let i = 0; i < characters.length; i++) {
        const oldValue = charactersMap.get(characters[i]);
        charactersMap.set(characters[i], oldValue? oldValue + 1 : 1);
    }

    for (let i = 0; i < document.length; i++) {
        const oldValue = documentMap.get(document[i]);
        documentMap.set(document[i], oldValue? oldValue + 1 : 1);
    }

    for(let documentKey of documentMap.keys()) {
        if (charactersMap.has(documentKey) === false) {
            return false;
        }
        if (documentMap.get(documentKey)! > charactersMap.get(documentKey)!) return false;
    }

    return true;
}




  