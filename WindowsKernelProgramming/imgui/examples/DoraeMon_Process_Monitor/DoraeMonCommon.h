#pragma once
#ifndef DORAEMONCOMMON_H
#define DORAEMONCOMMON_H

// short enumeration for processes
enum class ItemType : short
{
	None,
	ProcessCreate,
	ProcessExit,
	ThreadCreate,
	ThreadExit
};

// Main Base struct
struct ItemHeader
{
	ItemType Type;
	USHORT size;
	LARGE_INTEGER Time;
};

struct ProcessExitInfo : ItemHeader
{
	ULONG ProcessId;
};

struct ProcessCreateInfo : ItemHeader
{
	ULONG ProcessId;
	ULONG ParentProcessId;
	USHORT CommandLineLength;
	USHORT CommandLineOffset;
	USHORT ImageFileNameLength;
	USHORT ImageFileNameOffset;
};

struct ThreadCreateExitInfo : ItemHeader
{
	ULONG ThreadId;
	ULONG ProcessId;
};


#endif // !DORAEMONCOMMON_H
