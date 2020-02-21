// expatpp
#ifndef H_EXPATPP
#define H_EXPATPP

#include "xmlparse.h"

/*
expatpp follows a simple pattern for converting the semi-OOP callback design of 
expat into a true class which allows you to override virtual methods to supply
callbacks.

USING expatpp
see testexpatpp.cpp for a detailed example

1) decide which callbacks you wish to use, eg: just startElement

2) declare a subclass of expatpp, eg:
class myExpat : public expatpp {
	virtual void startElement(const XML_Char* name, const XML_Char** atts);
};

3) create an instance of your object and pass in a buffer to parse
myExpat parser;
parser.XML_Parse(buf, len, done)


HOW IT WORKS
The User Data which expat maintains is simply a pointer to an instance of your object.

Inline static functions are specified as the callbacks to expat.
These static functions take the user data parameter returned from expat and cast it
to a pointer to an expatpp object.

Using that typed pointer they then call the appropriate virtual method.

If you have overriden a given virtual method then your version will be called, otherwise
the (empty) method in the base expatpp class is called.

NOTE:
For efficiency, you could provide your own constructor and set some of the callbacks
to 0, so expat doesn't call the static functions. (untested idea).

*/


class expatpp 
{
public:
	expatpp(bool createParser=true);
	virtual ~expatpp();

	operator XML_Parser() const;
	
	bool emptyCharData(const XML_Char* s, int len);  // utility often used in overridden charData

// overrideable callbacks
	virtual void startElement(const XML_Char* name, const XML_Char** atts);
	virtual void endElement(const XML_Char*);
	virtual void charData(const XML_Char*, int len);
	virtual void processingInstruction(const XML_Char* target, const XML_Char* data);
	virtual void defaultHandler(const XML_Char*, int len);
	virtual int notStandaloneHandler();
	virtual void unparsedEntityDecl(const XML_Char* entityName, const XML_Char* base, const XML_Char* systemId, const XML_Char* publicId, const XML_Char* notationName);
	virtual void notationDecl(const XML_Char* notationName, const XML_Char* base, const XML_Char* systemId, const XML_Char* publicId);
	virtual void startNamespace(const XML_Char* prefix, const XML_Char* uri);
	virtual void endNamespace(const XML_Char*);
	
// XML interfaces
	int XMLPARSEAPI XML_Parse(const char* buffer, int len, int isFinal);
	XML_Error XMLPARSEAPI XML_GetErrorCode();
	int XMLPARSEAPI XML_GetCurrentLineNumber();
	
protected:
	XML_Parser mParser;

// interface functions for callbacks
public:
	static void startElementCallback(void *userData, const XML_Char* name, const XML_Char** atts);
	static void endElementCallback(void *userData, const XML_Char* name);
	static void startNamespaceCallback(void *userData, const XML_Char* prefix, const XML_Char* uri);
	static void endNamespaceCallback(void *userData, const XML_Char* prefix);
	static void charDataCallback(void *userData, const XML_Char* s, int len);
	static void processingInstructionCallback(void *userData, const XML_Char* target, const XML_Char* data);
	static void defaultHandlerCallback(void* userData, const XML_Char* s, int len);
	static int notStandaloneHandlerCallback(void* userData);	
	static void unParsedEntityDeclCallback(void* userData, const XML_Char* entityName, const XML_Char* base, const XML_Char* systemId, const XML_Char* publicId, const XML_Char* notationName);
	static void notationDeclCallback(void *userData, const XML_Char* notationName, const XML_Char* base, const XML_Char* systemId, const XML_Char* publicId);
	
// utilities
	static int skipWhiteSpace(const char*);	
};


class expatppNesting : public expatpp {
// subclass to support a hierarchy of parsers, in a sort of recursion or
// 'nesting' approach, where a top-level parser might create sub-parsers for part of a file

public:
	expatppNesting();
	expatppNesting(expatppNesting* parent);  // NOT a copy ctor!! this is a recursive situation
	virtual ~expatppNesting();
	
	expatppNesting* returnToParent();

protected:
	int	mDepth;	
	expatppNesting* mParent;

// interface functions for callbacks
public:
	static void nestedStartElementCallback(void* userData, const XML_Char* name, const XML_Char** atts);
	static void nestedEndElementCallback(void* userData, const XML_Char* name);
};

// inlines

// -------------------------------------------------------
//      e x p a t p p
// -------------------------------------------------------
inline 	
expatpp::operator XML_Parser() const
{
	return mParser;
}


inline int XMLPARSEAPI 
expatpp::XML_Parse(const char *s, int len, int isFinal)
{
	return ::XML_Parse(mParser, s, len, isFinal);
}


inline XML_Error 
expatpp::XMLPARSEAPI XML_GetErrorCode()
{
	return ::XML_GetErrorCode(mParser);
}


inline int XMLPARSEAPI 
expatpp::XML_GetCurrentLineNumber()
{
	return ::XML_GetCurrentLineNumber(mParser);
}


#endif
